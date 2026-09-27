class Solution {
    public boolean isPalindrome(String s) {
        String ans = "";
        s = s.toLowerCase();

        for (int i = 0; i < s.length(); i++) {

          
            if ((s.charAt(i) < 'a' || s.charAt(i) > 'z') &&
                (s.charAt(i) < '0' || s.charAt(i) > '9')) {
                continue;
            }

            ans += s.charAt(i);
        }

        int left = 0;
        int right = ans.length() - 1;

        while (left < right) {
            if (ans.charAt(left) != ans.charAt(right)) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
}