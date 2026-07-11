
auto fast = [](){ ios::sync_with_stdio(false); cin.tie(NULL);return 0; }();
// leetcode contest
#define ll                    long long


template<typename T > class SegmentTree {
    private:
    vector< T > tree;
    int n ;
    T  pull( T  a , T b )
    {
        return max( a , b );
    }
    T  query(int u , int l , int r , const int tl , const int tr ) {
        if ( r < tl || l > tr ) {
            return pull(tree[0],tree[0]) ;
        }
        if ( tl <= l && tr >= r) {
            return tree[u];
        }
        int m = ( l + r ) / 2;
        return pull(query(2 * u, l, m, tl, tr), query(2 * u + 1, m + 1, r, tl, tr));
    }
    
    void update(int u , int l , int r , const int pos , const T val )
    {
        if ( l == r) {
            tree[u] = max( tree[u] , val)  ;
            return;
        }
        int m = ( l + r ) / 2;
        if ( pos <= m )update( 2 * u , l , m , pos , val );
        else update( 2 * u + 1, m + 1 , r , pos , val );
        tree[u] = pull(tree[2 * u], tree[2 * u + 1]);
    }
    public:
    SegmentTree(){}
    SegmentTree ( int n )
    {
        this->n = n ;
        tree.resize( 4 * n + 1 ,0 ) ;
    }
    void update( int i , T val)
    {
        update( 1 , 0 , n - 1 , i , val  );
    }
    T query( int l , int r  )
    {
        T  res =  query( 1 , 0 , n - 1 , l , r ) ;
        return res  ;
    }
};


class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element( nums.begin() , nums.end() );
        SegmentTree< ll > seg0( mx + 1 );
        SegmentTree< ll > seg1( mx + 1 );
        vector< ll > ans0( n );
        vector< ll > ans1( n );
        ll res = 0 ; 
        //Starting from end 
        for( int i = n - 1 ; i >= 0 ; i-- ){
            if( i + k < n ){
                seg0.update( nums[i+k] , ans0[i+k]);
                seg1.update( nums[i+k] , ans1[i+k]);
            }
            ans0[i] = nums[i] + seg1.query( nums[i] + 1 , mx );
            ans1[i] = nums[i] + seg0.query( 1 , nums[i] - 1 );
            res = max( { res , ans0[i] , ans1[i]});
        }
        return res ; 
    }
};