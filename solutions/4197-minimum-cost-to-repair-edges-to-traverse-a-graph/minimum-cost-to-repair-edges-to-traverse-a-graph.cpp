class Solution {
public:
    using Graph = unordered_map< int, vector< pair< int, int > > >;
    
    int _steps_count { 0 };
    int _target_node { 0 };

    auto bfs(int max_weight, Graph const& g) -> bool
    {
        auto queue = deque<pair<int,int>> {};
        queue.push_back( { 0, 0 } );

        auto seen = set<int> {};
        seen.insert(0);

        while( not queue.empty() )
        {
            auto [ node, steps ] = queue.front();
            queue.pop_front();

            if( _target_node - 1 == node )
            {
                return true;
            }
            if( auto neighbors = g.find( node ); g.end() != neighbors and steps < _steps_count )
            {
                for( auto const& [ neighbor, cost ] : neighbors->second )
                {
                    if( not seen.contains( neighbor ) and cost <= max_weight )
                    {
                        seen.insert( neighbor );
                        queue.push_back( { neighbor, steps + 1 } );
                    }
                }
            }
        }

        return false;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        _steps_count = k;
        _target_node = n;

        auto g = Graph {};
        int max_weight { 0 };

        for( auto e : edges )
        {
            auto from = e[ 0 ];
            auto to = e[ 1 ];
            auto cost = e[ 2 ];
            max_weight = max( max_weight, cost );
            g[ from ].push_back( { to, cost } );
            g[ to ].push_back( { from, cost } ); 
        }

        int l { 0 };
        int r { max_weight };

        while( l <= r )
        {
            int m = ( l + r ) / 2;
            if( bfs( m, g ) )
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        return ( l > max_weight ) ? ( -1 ) : ( l );
    }
};