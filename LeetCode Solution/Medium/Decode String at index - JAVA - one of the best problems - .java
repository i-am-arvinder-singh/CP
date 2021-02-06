class Solution {
    public String decodeAtIndex(String S, int K) {
        long cur = 0;
        Integer n = S.length();
        for(Integer i=0;i<n;i++){
            char ch = S.charAt(i);
            if(Character.isDigit(ch)){
                cur*=Integer.parseInt(Character.toString(ch));
            } else {
                cur++;
            }
        }
        for(Integer i=n-1;i>=0;i--){
            char ch = S.charAt(i);
            K%=cur;
            if(!Character.isDigit(ch) && K==0){
                return Character.toString(ch);
            }
            if(Character.isDigit(ch)){
                cur=cur/Integer.parseInt(Character.toString(ch));
            } else {
                cur--;
            }
        }
        return "";
    }
}