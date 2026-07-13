import numpy as np

class Solution:
    def countValidSubsets(self, parent: List[int], nums: List[int], k: int) -> int:
        n = len(parent)
        MOD = 10**9 + 7
        
        # 1. Precompute a structural mapping matrix for vectorized modular convolution.
        # transition_matrix[i, j] will contain the remainder (i + j) % k.
        # We broadcast a meshgrid to compute this instantly for the entire k x k space.
        idx_i, idx_j = np.meshgrid(np.arange(k), np.arange(k), indexing='ij')
        sum_mod_k = (idx_i + idx_j) % k
        
        # Build binary selection masks of shape (k, k, k)
        # mask[r] is a 2D boolean grid highlighting where (i + j) % k == r
        convolution_mask = (sum_mod_k[-1, None, None] == np.arange(k)[:, None, None])
        convolution_mask = (sum_mod_k[None, :, :] == np.arange(k)[:, None, None])

        # Alternately, an elegant way to perform a fast modular reduction without looping:
        # We can construct a sparse/dense index matrix to accumulate the outer product.
        # Let's map pairs directly using an explicit index transformation.
        indices = sum_mod_k.ravel()
        
        # 2. Instantiate the global state tensor: Shape (n, 2, k)
        dp = np.zeros((n, 2, k), dtype=np.int64)
        dp[:, 0, 0] = 1
        
        # Plant the initial base states for selected configurations
        for i in range(n):
            rem = nums[i] % k
            dp[i, 1, rem] = (dp[i, 1, rem] + 1) % MOD

        # 3. Backward Topological Flattened Sweep
        for c in range(n - 1, 0, -1):
            p = parent[c]
            
            # Extract parent vectors
            p_none = dp[p, 0, :]
            p_some = dp[p, 1, :]
            
            # Child aggregated vectors
            c_any = (dp[c, 0, :] + dp[c, 1, :]) % MOD
            c_none = dp[c, 0, :]
            
            # Compute 2D Outer Products (Shape: k x k)
            outer_none = (p_none[:, None] * c_any[None, :]) % MOD
            outer_some = (p_some[:, None] * c_none[None, :]) % MOD
            
            # Flatten outer products and use np.bincount to perform the modular bucket reductions.
            # This completely bypasses any internal loops or np.roll overhead.
            dp[p, 0, :] = np.bincount(indices, weights=outer_none.ravel(), minlength=k).astype(np.int64) % MOD
            dp[p, 1, :] = np.bincount(indices, weights=outer_some.ravel(), minlength=k).astype(np.int64) % MOD

        # 4. Extract total valid configurations at the root node
        total_subsets = (dp[0, 0, 0] + dp[0, 1, 0]) % MOD
        
        # Eliminate the completely empty subset configuration
        return int((total_subsets - 1 + MOD) % MOD)      