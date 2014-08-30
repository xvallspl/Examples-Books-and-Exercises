package Money;
public class Dollar{
	
	public Dollar(int amount)
	{
		this.amount=amount;
	}

	public Dollar times(int multiplier){
		return new Dollar(amount*multiplier);
	}

	int amount;
}