/*
    Problem Statement:
    ------------------
    We are given two strings:

            source
            target

    Along with several transformation rules.

    Every rule consists of

            pattern -> replacement

    where

            pattern.length == replacement.length

    and the pattern may contain wildcard '*' characters.

    Applying a rule:

        • The pattern must match the current substring.
        • '*' matches any character.
        • The replacement must exactly become the target substring.
        • The cost is

                baseCost + numberOfWildcards

    Every character position can participate in AT MOST one rule.

    We need to find the minimum total cost to transform source into target.


    Initial Thoughts:
    -----------------

    Since positions cannot be reused, once we decide how a character is
    transformed, it can never be touched again.

    Also,

            replacement.length == pattern.length

    Therefore, character positions never shift.

    Every position belongs to exactly one of two categories:

            1. Left unchanged.
            2. Covered by exactly one rule.

    Since rules never overlap, we can process the string strictly
    from left to right.

    This naturally suggests Dynamic Programming on prefixes.

    DP State:
    ---------

    Let

            dp[i]

    denote the minimum cost required to correctly transform the first
    i characters.

    Initially,

            dp[0] = 0

    since transforming an empty prefix costs nothing.

    All other states are initialized to infinity.

    Transition 1:
    -------------

    Suppose we are currently at position i.

    If

            source[i] == target[i]

    then we may simply leave this character unchanged.

    Hence,

            dp[i+1] = min(dp[i+1], dp[i])


    Transition 2:
    -------------

    Try every rule starting at position i.

    For a rule to be applicable:

        1. The rule must fit inside the string.

        2. Pattern must match the source.

                For every position:

                    pattern[k] == source[i+k]

                OR

                    pattern[k] == '*'

        3. Replacement must already equal the target substring.

                replacement[k] == target[i+k]

    If all three conditions hold, we may apply this rule.

    Suppose

            rule length = L

    Then the next DP state becomes

            dp[i+L]

    and the transition is

            dp[i+L]
            =
            min(dp[i+L],
                dp[i] + ruleCost + wildcardCount)


    Matching Function:
    ------------------

    The helper function check() simply verifies whether a rule can be
    applied starting at a given position.

    It returns false if

        • rule exceeds string boundary
        • pattern does not match source
        • replacement does not match target

    Otherwise it returns true.

    Why This Works:
    ---------------

    Since positions can never overlap,

    once the first i characters have been processed,
    they will never be modified again.

    Therefore,

            dp[i]

    completely describes every necessary piece of information about the
    processed prefix.

    From this state there are only two possibilities:

        • Leave the current character unchanged.

        • Start one valid rule here.

    Trying every rule guarantees that every valid transformation is
    considered.

    Since every transition preserves correctness of the processed prefix,
    the DP eventually computes the minimum possible cost.


    Complexity Analysis:
    --------------------

    Let

            n = source.length
            m = number of rules
            L = maximum rule length

    For every position we try every rule.

    Verifying one rule takes O(L).

    Therefore,

            Time Complexity:

                    O(n × m × L)

    With the constraints,

            n <= 5000
            m <= 200
            L <= 20

    the total work is roughly

            5000 × 200 × 20
            = 20,000,000

    character comparisons.

    Space Complexity:

            O(n)

    for the DP array.
*/

class Solution {
    public int minCost(String source, String target, List<List<String>> rules, int[] costs) {

        if(source.equals(target)) return 0 ;

        char[] s = source.toCharArray() ;
        char[] t = target.toCharArray() ;

        int n = s.length ;

        int[] starCount = new int[rules.size()] ;

        for(int i = 0 ; i < rules.size() ; i ++)
        {
            for(char c : rules.get(i).get(0).toCharArray())
            {
                if(c == '*') starCount[i]++ ;
            }
        }

        int[] dp = new int[n + 1] ;
        Arrays.fill(dp, Integer.MAX_VALUE) ;
        dp[0] = 0 ;

        for(int i = 0 ; i < n ; i ++)
        {
            if(dp[i] == Integer.MAX_VALUE) continue ;

            if(s[i] == t[i])
            {
                dp[i + 1] = Math.min(dp[i + 1], dp[i]) ;
            }

            for(int j = 0 ; j < rules.size() ; j ++)
            {
                List<String> rule = rules.get(j) ;

                String p = rule.get(0) ;
                String r = rule.get(1) ;

                int l = p.length() ;

                boolean f = check(s, t, i, p, r, l, n) ;

                //System.out.println(j + "|" + f) ;

                if(f)
                {
                    dp[i + l] = Math.min(dp[i + l], dp[i] + costs[j] + starCount[j]) ;
                }
            }
        }

        return dp[n] == Integer.MAX_VALUE ? -1 : dp[n] ;
        
    }

    boolean check(char[] s, char[] t, int idx, String p, String r, int l, int n)
    {
        if(n - idx < l) return false ;

        int j = 0 ;

        for(int i = idx ; i < idx + l ; i ++)
        {
            if(p.charAt(j) != '*' && p.charAt(j) != s[i]) return false ;

            if(r.charAt(j) != t[i]) return false ;

            j ++ ;
        }

        return true ;
    }
}