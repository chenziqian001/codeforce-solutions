package chap;

public class Hitgreenpig1 {
    public static void main(String[] args) {
        AngryBird[] s = new AngryBird[3];
        int n;
        for (int i = 0; i < s.length; i++) {
            n = (int) (Math.random() * 3);
            switch (n) {
                case 0:
                    s[i] = new BlueBird();
                    break;
                case 1:
                    s[i] = new WhiteBird();
                    break;
                case 2:
                    s[i] = new RedBird();
                    break;
            }
        }
        for (int i = 0; i < s.length; i++) {
            s[i].shoot();
        }
    }
}
package chap;
public class Hitgreenpig {
    public static void main(String[] args) {
        BlueBird one = new BlueBird();
        one.chirp();
        one.shoot();

        WhiteBird two = new WhiteBird();
        two.chirp();
        two.shoot();

        RedBird three = new RedBird();
        three.chirp();
        three.shoot();
    }
}