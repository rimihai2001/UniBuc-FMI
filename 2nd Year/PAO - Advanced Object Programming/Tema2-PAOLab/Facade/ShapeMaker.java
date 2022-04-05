public class ShapeMaker {
    private Shape circle;
    private Shape rectangle;
    private Shape square;

    public ShapeMaker() {
        circle = new Circle((int) Math.floor(Math.random() * (30 - 1 + 1) + 1));
        rectangle = new Rectangle((int) Math.floor(Math.random() * (30 - 1 + 1) + 1),
                (int) Math.floor(Math.random() * (30 - 1 + 1) + 1));
        square = new Square((int) Math.floor(Math.random() * (30 - 1 + 1) + 1));
    }

    public void drawCircle() {
        circle.draw();
    }

    public void drawRectangle() {
        rectangle.draw();
    }

    public void drawSquare() {
        square.draw();
    }
}