class Solution {
public:
    vector<vector<int>> generateSchedule(int n) {
        if (n <= 4)
            return {};

        int total_matches = n * (n - 1);

        unordered_set<int> teams;
        vector<int> gamesPlayed(n, 0);
        vector<vector<bool>> matches(n,vector<bool>(n,false));

        int lastPlayedTeam1 = -1 , lastPlayedTeam2 = -1;

        for(int i=0 ; i<n ;  i++){
            teams.insert(i);
        }

        vector<vector<int>> schedule;

        for(int day = 0 ; day < total_matches ; day++){

            unordered_set<int> available;
            for(int team : teams){
                if(team != lastPlayedTeam1 && team != lastPlayedTeam2){
                    available.insert(team);
                }
            }

            int miniScore = INT_MAX;
            int Firstteam = -1;
            int Secondteam = -1;

            for(int team1 : available){
                for(int team2 : available){
                    if(team1 == team2) continue;
                    if(matches[team1][team2]) continue;

                    int score = gamesPlayed[team1] + gamesPlayed[team2];
                    if(score < miniScore){
                        miniScore = score;
                        Firstteam = team1;
                        Secondteam = team2;
                    }
                }
            }

            if(Firstteam == -1 || Secondteam == -1) return {};

            schedule.push_back({Firstteam , Secondteam});
            matches[Firstteam][Secondteam] = true;
            lastPlayedTeam1 = Firstteam;
            lastPlayedTeam2 = Secondteam;
            gamesPlayed[Firstteam]++;
            gamesPlayed[Secondteam]++;
        }
        return schedule;
    }
};