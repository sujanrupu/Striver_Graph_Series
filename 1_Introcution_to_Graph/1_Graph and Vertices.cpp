class Solution {
  public:
    long long count(int n) {
        return pow(2, (n * (n-1))/2);
    }
};
