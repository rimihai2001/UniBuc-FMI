import java.util.Scanner;

public class FacadeDemo {
    public static void main(String[] args) {
        ShapeMaker shapeMaker = new ShapeMaker();
        System.out.println("WHAT TO DRAW MENU");
        System.out.println("1 - Draw a circle");
        System.out.println("2 - Draw a rectangle");
        System.out.println("3 - Draw a square");
        System.out.print("Choose an option: ");

        try (Scanner scan = new Scanner(System.in)) {
            int option = scan.nextInt();

            switch (option) {
                case 1:
                    shapeMaker.drawCircle();
                    break;
                case 2:
                    shapeMaker.drawRectangle();
                    break;
                case 3:
                    shapeMaker.drawSquare();
                    break;
                default:
                    System.out.println("Invalid option!!!");
            }
        }
        catch(Exception e){
            System.out.println("Something went wrong. Try again!");
        }
    }

}