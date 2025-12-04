
package chap;
import java.io.*;
public class Ex10_5 {

    public static void main(String[] args) throws IOException {
        // TODO 自动生成的方法存根
        String filename="D://newHello.txt";
        String line;
        BufferedReader in =new BufferedReader(new FileReader(filename));
        line=in.readLine();
        while(line!=null){
            System.out.println(line);
            line=in.readLine();
        }
        in.close();
    }

}
