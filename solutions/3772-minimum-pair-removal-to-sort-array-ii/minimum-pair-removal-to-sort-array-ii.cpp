typedef long long ll;
class Node {
public:
    Node *prev, *next;
    ll val, idx;
    Node(ll val, ll idx) : prev{nullptr}, next{nullptr}, val{val}, idx{idx} {}

    // delete root to prevent memory leaks
    void nuke() {
        if (this->next) {
            this->next->nuke();
        }
        delete this;
    }

    // prints nums as a list (debugging)
    void print() {
        Node* temp = this;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size(), res = 0;
        
        // hashmap between index and node
        vector<Node*> dir(n, nullptr);

        // maintains ordered list of {adj sum, right idx}
        set<pair<ll, ll>> st;

        Node* root = new Node(nums[0], 0);
        Node* tail = root;
        dir[0] = root;
        
        // track number of unsatisfied adjacencies
        int unsat = 0;

        // build nums as a linked list
        for (int i = 1; i < n; i++) {
            tail->next = new Node(nums[i], i);
            tail->next->prev = tail;
            tail = tail->next;
            if (nums[i-1] > nums[i]) {
                unsat++;
            }
            dir[i] = tail;

            st.emplace(nums[i] + nums[i-1], i);
        }

        // repeat removals until all adj satisfied
        while (unsat) {
            res++;
            
            // remove lowest, leftmost sum
            pair<ll, ll> pr = *st.begin();
            st.erase(st.begin());

            // retrieve right node of pair
            Node* temp = dir[pr.second];

            // erase prev and next adjacencies from the set
            if (temp->prev->prev) {
                st.erase(make_pair(temp->prev->prev->val + temp->prev->val, temp->prev->idx));
            }
            if (temp->next) {
                st.erase(make_pair(temp->val+temp->next->val, temp->next->idx));
            }
            
            // delete left node and remove any unsatisfied markers
            Node* del = temp->prev;
            if (del == root) root = temp;
            if (temp->val < del->val) unsat--;
            if (del->prev && del->val < del->prev->val) unsat--;
            
            temp->prev = del->prev;
            delete del;
            
            // reinsert pairs for {prev, curr} and {curr, next}
            if (temp->prev) {
                temp->prev->next = temp;
                st.emplace(pr.first + temp->prev->val, temp->idx);
            }
            if (temp->next) {
                st.emplace(pr.first + temp->next->val, temp->next->idx);
                // remove unsatisfied markers for right node
                if (temp->next->val < temp->val) unsat--;
            }

            // update node sum
            temp->val = pr.first;
            
            // update unsatisfied markers surrounding current node (temp)
            if (temp->prev && temp->val < temp->prev->val) unsat++;
            if (temp->next && temp->next->val < temp->val) unsat++;
        }
        // root->print();
        root->nuke();
        return res;
    }
};