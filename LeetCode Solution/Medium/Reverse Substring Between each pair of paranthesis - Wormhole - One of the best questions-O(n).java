class Solution {
    public String reverseParentheses(String s) {
        Integer n = s.length();
        Stack<Integer> st = new Stack<>();
        Integer [] pair = new Integer[n];
        for(Integer i=0;i<n;i++){
            if(s.charAt(i)=='(') st.push(i);
            else if (s.charAt(i)==')'){
                pair[i]=st.pop();
                pair[pair[i]]=i;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(Integer i=0,dir=1;i<n;i+=dir){
            if(s.charAt(i)=='('||s.charAt(i)==')'){
                i=pair[i];
                dir=-dir;//change direction
            }
            else {
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}