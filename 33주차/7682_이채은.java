import java.io.*;

public class Main{
    static char[][] tictactoe = new char[3][3];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            String s = br.readLine();
            if(s.equals("end")) break;
            char[] tmp = s.toCharArray();
            int X = 0, O = 0;
            for(int i=0; i<9; i++) {
            	tictactoe[i/3][i%3] = tmp[i];
            	if(tmp[i] == 'X') X++;
            	else if(tmp[i] == 'O') O++;
            }
            
            boolean Oflag = check('O'), Xflag = check('X');
            
            if(Oflag && !Xflag && O == X) {
            	System.out.println("valid");
            } else if(Xflag && !Oflag && X == O+1) {
            	System.out.println("valid");
            } else if(!Xflag && !Oflag && X == 5 && O == 4) {
            	System.out.println("valid");
            } else {
            	System.out.println("invalid");
            }
        }
    }
    
    public static boolean check(char c) {
    	for(int i=0; i<3; i++) {
    		boolean res1 = true, res2 = true;
    		for(int j=0; j<3; j++) {
    			if(tictactoe[i][j] != c) res1 = false;
    			if(tictactoe[j][i] != c) res2 = false;
    		}
    		if(res1 || res2) return true;
    	}
    	
    	boolean res3 = true, res4 = true;
    	for(int i=0; i<3; i++) {
    		if(tictactoe[i][i] != c) res3 = false;
    		if(tictactoe[i][2-i] != c) res4 = false;
    	}
    	if(res3 || res4) return true;
    	
    	return false;
    }
}
