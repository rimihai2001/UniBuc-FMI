public class OperationPower implements Calculator{
    @Override
    public int executeOperation(int x, int y) {
        return (int) Math.pow(x, y);
    }
}
