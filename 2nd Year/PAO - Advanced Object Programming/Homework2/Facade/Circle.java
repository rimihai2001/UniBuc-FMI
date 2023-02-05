public class Circle implements Shape {
    int radius=10;
    public Circle(){

    }

    public Circle(int r){
        radius=r;
    }
    @Override
    public void draw() {
       System.out.println("Draw a circle with radius="+radius+"cm");
    }
 }