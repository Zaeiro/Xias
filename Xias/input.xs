static class Math
{
    public static int PlusOne(int n)
    {
        return 1;
    }
}

namespace Woah
{
    public class NoWay
    {
        public static implicit operator bool(NoWay nw)
        {
            return false;
        }
    }
}

new public static class Apple
{
    private readonly int pug = 2, bear, nun = 3;
    protected static Pogger champ = 0, pumpkin;

    public ExampleClass example;

    public static int VeryCoolFunction(int not)
    {
        double value = 3.0, nval;
        pug = 45;
        this.pug = 22;
        example.stong = "yello";
        Math.PlusOne(1 + 2, 3, pug, "");
        Math.PlusOne("");
        return 3 == 1 ? (int)champ : Math.PlusOne(not);
    }

    protected class DerivedClass : ExampleClass.embeddedClass
    {

    }
}

public class ExampleClass
{
    private readonly int Apple = 33, Orange, Pear = 12 + 35;
    public int ReallyCoolNumber = 42;
    protected String stong = new String();

    public class embeddedClass
    {
        public int aaa;
    }
}
