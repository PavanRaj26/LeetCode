class Solution {
    public Boolean isCons(char C) {
        if (C == 'A' || C == 'a') {
            return false;
        }
        if (C == 'E' || C == 'e') {
            return false;
        }
        if (C == 'I' || C == 'i') {
            return false;
        }
        if (C == 'O' || C == 'o') {
            return false;
        }
        if (C == 'U' || C == 'u') {
            return false;
        }
        return true;
    }
    public String toGoatLatin(String S) {
        List<String> ll = Arrays.asList(S.split(" "));
        String ans = "";
        for (int i =0; i < ll.size(); i++) {
            String s = ll.get(i);
            String nn = "";
            String app = "";
            char c = s.charAt(0);
            for (int j =1; j <= i+1;j++) {
                app = app + "a";
            }
            if (isCons(c)) {
                nn = s.substring(1,s.length()) + s.charAt(0) + "ma" + app;
            } else {
                nn = s + "ma" +  app;
            }            
            ans = ans + nn + (i == ll.size() - 1?"":" ");
        }
        return ans;
    }
}
