class LUPrefix {
    vector<int> videos ;
    int cnt ;
    int prefix ;
public:
    LUPrefix(int n) {
        this->videos.resize(n+1,0) ;
        this->videos[0] = 1 ;
        this->cnt = 0 ;
        this->prefix = 0 ;
    }
    
    void upload(int video) {
        this->videos[video] = 1 ;
        ++cnt ;
    }
    
    int longest() {
        int i = prefix ;
        while(i <= cnt && videos[i] == 1) ++i ;
        prefix = i - 1 ;
        return prefix ;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */