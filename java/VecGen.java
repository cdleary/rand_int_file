import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Random;
import java.io.IOException;

class VecGen
{
    public static void main(String args[]) {
        if (args.length != 1) {
            System.err.println("Usage: VecGen <elem_count>");
            System.exit(-1);
        }

        int count = Integer.parseInt(args[0]);

        try {
            FileWriter fw = new FileWriter("vec_gen.out");
            BufferedWriter bw = new BufferedWriter(fw);

            Random rng = new Random();

            for (int i = 0; i < count; ++i) {
                int r = rng.nextInt();
                bw.write(r + "\n");
            }

            bw.close();
        } catch (IOException e) {
            System.err.println("Received I/O exception: " + e);
            System.exit(-2);
        }
    }
};
