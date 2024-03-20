class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        //Declaring the maxheap
        priority_queue<int>pq;

        // to store the frequency of the letters
        vector<int>frequency(26,0);
        for(char &ch: tasks){
            frequency[ch - 'A']++;
        }

        for(int i = 0; i < 26; i++){
            if(frequency[i] > 0){
                pq.push(frequency[i]);
            }
        }

        int totalTime = 0;
        //Untill the heap is completely empty
        while(!pq.empty()){
            vector<int>temp;
            for(int i = 1; i <= n + 1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    // Removing from maxheap
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(int &frequency: temp){
                if(frequency > 0){
                    pq.push(frequency);
                }
            }
            if(pq.empty()){
                totalTime += temp.size();
            }else{
                totalTime += (n + 1);
            }
        }
        return totalTime;
    }
};
