public class Rectangle implements Shape {
    int height = 10, width = 5;

    public Rectangle() {

    }

    public Rectangle(int h, int w) {
        height = h;
        width = w;
    }

    @Override
    public void draw() {
        System.out.println("Draw a rectangle with height=" + height + "cm and width=" + width + "cm");
    }
}