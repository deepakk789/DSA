class Solution {
public:
    int hammingWeight(uint32_t n) {
        // tc o(n) and sc o(1)
        // int cnt=0;
        // for(int i=0;i<32;i++){
        //     if((n>>i)&1) cnt++;
        // }
        // return cnt;

        // tc o(32) and o(1) 
        // works because in just previous numbers we have a property like 13 = 1101 then 12 will be = 1100 then 11 - will be - 1011 then 10 is 1010 the first set bit is converted to 0 and all previous bit are set to 1 in case of previous , so we will use this property and we know that after first set bit there is no change. so only first bit unsetted .
        int cnt=0;
        while(n){
            n&=n-1;
            cnt++;
        }
        return cnt;

    }
};
