class Solution {
    public String processStr(String s) {
        List<Character> st = new ArrayList<>();
        StringBuilder result = new StringBuilder();
        for(char character: s.toCharArray()){
            if(Character.isLetter(character)){
                st.add(character);
            }
            if(character == '*'){
                if(!st.isEmpty()){
                    st.remove(st.size() - 1);
                }
            }
            if(character == '#'){
                int stSize = st.size();
                for(int j = 0; j < stSize; ++j){
                    st.add(st.get(j));
                }
            }
            if(character == '%'){
                Collections.reverse(st);
            }
        }
        for(char ch: st){
            result.append(ch);
        }
        return result.toString();
    }
}
