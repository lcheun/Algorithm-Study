import java.io.*;

public class Main{
    static boolean[] notPrime = new boolean[1000001];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder res = new StringBuilder("");
        set();
        while(true){
            int n = Integer.parseInt(br.readLine());
            if(n == 0) break;
            int flag = 0;
            for(int i=3; i<=500000; i+=2){
                if(notPrime[i]==true) continue;
                if(notPrime[n-i]==false){
                    res.append(n+" = "+i+" + "+(n-i)+"\n");
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) res.append("Goldbach's conjecture is wrong.\n");
        }
        System.out.println(res);
    }
    
    public static void set(){
        for(int i=3; i<=1000000; i+=2){
            if(notPrime[i] == true) continue;
            for(int j=2*i; j<=1000000; j+=i)
                notPrime[j] = true;
        }
    }
}
