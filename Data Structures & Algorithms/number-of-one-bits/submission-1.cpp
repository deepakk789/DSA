class Solution {
public:
    int hammingWeight(uint32_t n) {
        // tc o(n) and sc o(1)
        // int cnt=0;
        // for(int i=0;i<32;i++){
        //     if((n>>i)&1) cnt++;
        // }
        // return cnt;

        //tc o(32) and o(1) 
        int cnt=0;
        while(n){
            n&=n-1;
            cnt++;
        }
        return cnt;

    }
};
