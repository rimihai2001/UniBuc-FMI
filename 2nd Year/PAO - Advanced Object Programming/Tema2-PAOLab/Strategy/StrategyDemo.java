import java.util.Scanner;

public class StrategyDemo {
    public static void main(String[] args) {
        System.out.println("CALCULATOR MENU");
        System.out.println("1 - Add");
        System.out.println("2 - Substract");
        System.out.println("3 - Multiply");
        System.out.println("4 - Divide");
        System.out.println("5 - Remainder");
        System.out.println("6 - Power");
        System.out.print("Choose an operation: ");
        try (Scanner scan = new Scanner(System.in)) {
            int option = scan.nextInt();

            switch (option) {
                case 1:
                    System.out.print("x: ");
                    Scanner scanx = new Scanner(System.in);
                    int x = scanx.nextInt();
                    System.out.print("y: ");
                    Scanner scany = new Scanner(System.in);
                    int y = scany.nextInt();
                    Context operatie = new Context(new OperationAdd());
                    if (operatie.execOp(x, y) >= Integer.MAX_VALUE || operatie.execOp(x, y) <= Integer.MIN_VALUE) {
                        throw new Exception("Error");
                    }
                    System.out.println("x + y = " + operatie.execOp(x, y));
                    break;
                case 2:
                    System.out.print("x: ");
                    scanx = new Scanner(System.in);
                    x = scanx.nextInt();
                    System.out.print("y: ");
                    scany = new Scanner(System.in);
                    y = scany.nextInt();
                    operatie = new Context(new OperationSubstract());
                    if (operatie.execOp(x, y) >= Integer.MAX_VALUE || operatie.execOp(x, y) <= Integer.MIN_VALUE) {
                        throw new Exception("Error");
                    }
                    System.out.println("x - y = " + operatie.execOp(x, y));
                    break;
                case 3:
                    System.out.print("x: ");
                    scanx = new Scanner(System.in);
                    x = scanx.nextInt();
                    System.out.print("y: ");
                    scany = new Scanner(System.in);
                    y = scany.nextInt();
                    operatie = new Context(new OperationMultiply());
                    if (operatie.execOp(x, y) >= Integer.MAX_VALUE || operatie.execOp(x, y) <= Integer.MIN_VALUE) {
                        throw new Exception("Error");
                    }
                    System.out.println("x * y = " + operatie.execOp(x, y));
                    break;
                case 4:
                    System.out.print("x: ");
                    scanx = new Scanner(System.in);
                    x = scanx.nextInt();
                    System.out.print("y: ");
                    scany = new Scanner(System.in);
                    y = scany.nextInt();
                    operatie = new Context(new OperationDivide());
                    if (operatie.execOp(x, y) >= Integer.MAX_VALUE || operatie.execOp(x, y) <= Integer.MIN_VALUE) {
                        throw new Exception("Error");
                    }
                    System.out.println("x / y = " + operatie.execOp(x, y));
                    break;
                case 5:
                    System.out.print("x: ");
                    scanx = new Scanner(System.in);
                    x = scanx.nextInt();
                    System.out.print("y: ");
                    scany = new Scanner(System.in);
                    y = scany.nextInt();
                    operatie = new Context(new OperationRemainder());
                    if (operatie.execOp(x, y) >= Integer.MAX_VALUE || operatie.execOp(x, y) <= Integer.MIN_VALUE) {
                        throw new Exception("Error");
                    }
                    System.out.println("x % y = " + operatie.execOp(x, y));
                    break;
                case 6:
                    System.out.print("x: ");
                    scanx = new Scanner(System.in);
                    x = scanx.nextInt();
                    System.out.print("y: ");
                    scany = new Scanner(System.in);
                    y = scany.nextInt();
                    operatie = new Context(new OperationPower());
                    if (operatie.execOp(x, y) >= Integer.MAX_VALUE || operatie.execOp(x, y) <= Integer.MIN_VALUE) {
                        throw new Exception("Error");
                    }
                    System.out.println("x ^ y = " + operatie.execOp(x, y));
                    break;
                default:
                    System.out.println("Invalid option!!!");
            }
        } catch (Exception e) {
            System.out.println("Out of Integer class. Please try again!");
        }
    }
}