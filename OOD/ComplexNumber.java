public class ComplexNumber {
    public static void main(String[] args) {
        Complex num1 = new Complex(3, 4);
        Complex num2 = new Complex(0, 0);

        System.out.println(num1.add(num2));

        System.out.println(num1.subtract(num2));

        System.out.println(num1.multiply(num2));

        try {
            System.out.println(num1.divide(num2));
        } catch (Exception e) {
           e.printStackTrace();
        }
    }
}

class Complex {
    private float re;
    private float im;

    Complex() {
    }

    Complex(float re, float im) {
        this.re = re;
        this.im = im;
    }

    public Complex add(Complex n) {
        Complex num = new Complex();
        num.re += n.re;
        num.im += n.im;
        return num;
    }

    public Complex subtract(Complex n) {
        Complex num = new Complex();
        num.re -= n.re;
        num.im -= n.im;
        return num;
    }

    public Complex multiply(Complex n) {
        Complex num = new Complex();
        num.re = re * n.re - im * n.im;
        num.im = im * n.re + re * n.im;
        return num;
    }

    public Complex divide(Complex n) {
        Complex num = new Complex();
        float sq = n.re * n.re + n.im * n.im;
        if (sq == 0) {
            throw new ArithmeticException();
        }
        num.re = (re * n.re + im * n.im) / sq;
        num.im = (im * n.re - re * n.im) / sq;
        return num;
    }

    public String toString() {
        return re + " + (" + im + ")i";
    }
}