public class Context {
    private Calculator calculator;

    public Context(Calculator strategy) {
        this.calculator = strategy;
    }

    public int execOp(int x, int y) {
        return calculator.executeOperation(x, y);
    }
}