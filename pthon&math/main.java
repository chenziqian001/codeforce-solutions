package javacccc;
import java.io.*;
public class Ex10_6 {
    public static void main(String[] args) throws IOException {
        FileOutputStream fos = new FileOutputStream("D:/myjava/a.dat");
        DataOutputStream dos = new DataOutputStream(fos);
        dos.writeBoolean(true);
        dos.writeByte((byte)123);
        dos.writeChar('K');
        dos.writeDouble(3.141592654);
        dos.writeFloat(2.2345f);
        dos.writeInt(1234567890);
        dos.writeLong(1234567890123456789L);
        dos.writeShort((short)1234);
        dos.writeUTF("string string string");
        dos.close();
    }
}


package javacccc;
import java.io.*;
public class Ex10_7 {
    public static void main(String[] args) throws IOException {
        String fileName = "D:/myjava/Binary.dat";
        DataOutputStream dataOut = new DataOutputStream(new BufferedOutputStream(new FileOutputStream(fileName)));
        dataOut.writeInt(0);
        System.out.println(dataOut.size() + " bytes have been written.");
        dataOut.writeDouble(31.2);
        System.out.println(dataOut.size() + " bytes have been written.");
        dataOut.writeBytes("this is string");
        System.out.println(dataOut.size() + " bytes have been written.");
        dataOut.close();
    }
}



package javacccc;
import java.io.*;
public class Ex10_9 {
    public static void main(String[] args) {
        String fileName = "D:/myjava/a.dat";
        int sum = 0;
        try {
            DataInputStream ins = new DataInputStream(new BufferedInputStream(new FileInputStream(fileName)));
            System.out.println("\t" + ins.readBoolean());
            System.out.println("\t" + ins.read());
            System.out.println("\t" + ins.readChar());
            System.out.println("\t" + ins.readDouble());
            System.out.println("\t" + ins.readFloat());
            System.out.println("\t" + ins.readInt());
            System.out.println("\t" + ins.readLong());
            System.out.println("\t" + ins.readShort());
            System.out.println("\t" + ins.readUTF());
            ins.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}