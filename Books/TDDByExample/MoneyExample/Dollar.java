package Money;
public class Dollar{
	
	public Dollar(int amount)
	{
		this.amount=amount;
	}

	public void times(int multiplier){
		amount*=multiplier;
	}

	int amount;
}