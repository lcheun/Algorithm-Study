import java.util.*;

public class Main{
    static char[] str;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        str = sc.next().toCharArray();
        Stack<Character> stk = new Stack<>();
        int ans = 0, cur = 1;
        for(int i=0; i<str.length; i++){
            if(str[i]=='('){
                stk.push('('); cur *= 2;
            } else if(str[i]=='['){
                stk.push('['); cur *= 3;
            }
            
            else if(str[i]==']' && !stk.empty() && stk.peek()=='['){
                if(str[i-1]=='[') ans += cur;
                stk.pop(); cur /= 3;
            } else if(str[i]==')' && !stk.empty() && stk.peek()=='('){
            	if(str[i-1]=='(') ans += cur;
                stk.pop(); cur /= 2;
            } else{
                ans = 0; break;
            }
        }
        
        if(!stk.empty()) ans = 0;
        System.out.println(ans);
        sc.close();
    }
}
