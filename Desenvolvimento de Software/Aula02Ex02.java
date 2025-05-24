
/*
2. Encontre o maior e o menor número informados no vetor anterior. 
*/
import java.util.Scanner;
public class Aula02Ex02 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
 

 int[] nuns = {1, 2, 3, 4, 5};
int menor=999999, maior=0;

for(int i = 0  ; i < nuns.length;i++ ){
   if(nuns[i]>maior){
    maior=nuns[i];
    
   }
        }

        System.err.println("o maior valor eh"+maior);

        for(int i = 0  ; i < nuns.length;i++ ){
            if(nuns[i]<menor){
             menor=nuns[i];
             
            }
                 }
         
                 System.err.println("o menor valor eh"+menor);
         
         
         


    for(int i = 0  ; i < nuns.length;i++ ){
        System.out.print("|"+nuns[i]);
            }

            System.out.print("|");
    }
}
