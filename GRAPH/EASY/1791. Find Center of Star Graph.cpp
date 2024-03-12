int init = [] {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ofstream out("user.out");
	cout.rdbuf(out.rdbuf());
	for (string line; getline(cin, line); cout << '\n') {
		istringstream ss(line);
		char ch;
		int a, b, c, d;
		ss >> ch >> ch >> a >> ch >> b >> ch >> ch >> ch >> c >> ch >> d;
		if (a == c || a == d) cout << a;
		else cout << b;
	}
	exit(0);
	return 0;
}();
class Solution {
public:
    __attribute__((disable_sanitizer_instrumentation))
    int findCenter(vector<vector<int>>& edges) {
        int nodes = edges.size() + 2;
        vector<vector<int>>adjList(nodes);
        for(int i = 0; i < edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 1; i <= nodes + 1; i++){
            if(adjList[i].size() == edges.size()){
                return i;
            }
        }
        return 0;
    }
};
