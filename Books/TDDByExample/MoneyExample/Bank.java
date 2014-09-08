package money;

public class Bank {

	Bank(){
		
	}
	
	Money reduce(Expression source, String to) {
		return source.reduce(to);
	}
	
}
