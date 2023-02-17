import java.util.*;

public class Main{
    private static int L, C;
    private static String[] arr;
    private static String[] vowel = {"a", "e", "i", "o", "u"};
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        L = sc.nextInt();
        C = sc.nextInt();
        arr = new String[C];
        for(int i=0; i<C; i++){
            arr[i] = sc.next();
        }
        
        Arrays.sort(arr);
        for(int i=0; i<=C-L; i++) {
        	dict(new StringBuilder(""), i, 0, 0, 0);
        }
        sc.close();
    }
    
    public static void dict(StringBuilder str, int idx, int v, int c, int pos){
        str.append(arr[idx]);
        if(chk(idx)) v++;
        else c++;
        
        if(pos == L-1){
            if(v>0 && c>1) System.out.println(str);
            return;
        }
        
        for(int i=idx+1; i<C; i++){
        	dict(new StringBuilder(str), i, v, c, pos+1);
        }    
        
    }
    
    public static boolean chk(int idx) {
    	for(String j:vowel) {
    		if(j.equals(arr[idx])) {
    			return true;
    		}
    	}
    	return false;
    }
}
