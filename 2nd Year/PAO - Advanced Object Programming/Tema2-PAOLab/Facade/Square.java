public class Square implements Shape {
    int lenght;

    public Square() {

    }

    public Square(int l) {
        lenght = l;
    }

    @Override
    public void draw() {
        System.out.println("Draw a square with length=" + lenght + "cm");
    }
}