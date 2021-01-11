class Solution {
public:
    int createSortedArray(vector<int>& instructions){
	if(instructions.empty()){
		return 0;
	}

	int maxVal = *max_element(instructions.begin(), instructions.end());
	long long minCost = 0;
	vector<int> fenwickTree(maxVal + 1);
	for(auto n : instructions){
		minCost = (minCost + min(get(fenwickTree, n - 1), get(fenwickTree, maxVal) - get(fenwickTree, n))) % 1000000007;
		add(fenwickTree, n, 1);
	}
	return minCost;
}

int get(const vector<int>& fenwickTree, int i){
	int res = 0;
	while(i > 0){
		res += fenwickTree[i];
		i -= i & -i;
	}
	return res;
}

void add(vector<int>& fenwickTree, int i, int val){
	while(i < fenwickTree.size()){
		fenwickTree[i] += val;
		i += i & -i;
	}
}
};