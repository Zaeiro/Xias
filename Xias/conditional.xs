namespace k
{
	public class lb
	{
		apol pl;
		public lb() {}
		public lb(int i) {}
		public static implicit operator rb(lb L) { return new rb(1, 0.0, ""); }
		public static int getValue() { return 1; }
	}
}
public class rb
{
	public static implicit operator k.lb(rb R) { return new k.lb(); }
	public static implicit operator ab(rb R) { return new ab(); }
}
public class ab
{
	
}
public class Program
{
	public static void Main()
	{
		ab p = (true ? 0.0 : "");
		ab dfdf = (true ? new k.lb() : new rb());
		ab adadd = (true ? new rb() : new k.lb());
		ab asd8iyugb = (true ? new k.lb() : new rb());
		//int[,][] arra = new int[2,2][];

		ab a = new ab();
		ab b = new ab();
		(true ? a : b) = new ab();
		Console.WriteLine("Hello World");
		lb.getValue("Hello World");
		lb.getValue();
		k.lb.getValue("Hello World");
		k.lb.getValue();
		int value = k.lb.getValue();
		int value = k.lb.getValue();
		value = k.lb.getValue("");
		value = lb.getValue();
	}
}