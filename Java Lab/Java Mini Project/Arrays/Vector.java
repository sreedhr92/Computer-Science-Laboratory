// Class for Vector operations

package Arrays;
import java.util.Random;

public class Vector implements ArrayType{
	public double vec[];
	private int vecShape;

	public void init(String in){
		if(in.equals("ones")){
			for(int i = 0; i<vecShape; i++)
				vec[i]= (double)1;
		}
		else if(in.equals("random")){
			Random r = new Random();
			for(int i = 0; i<vecShape; i++)
				vec[i] = r.nextGaussian();
		}
		else{
			// Throw excpetion, invalid string
		}
	}

	public Vector(double vector[]){	
		vecShape = vector.length;
		vec = vector;
	}

	public Vector(int m, String...in){
		vecShape = m;
		vec = new double[m];

		if(in.length > 1);
			// throw exception
		if(in.length == 0)
			return;
		init(in[0]);
	}

	public int shape(){
		return vecShape;
	}

	public double dot(Vector M){
		// Size mismatch..
		double total = 0.0;
		for(int i=0; i<M.shape(); i++) 
			total += (vec[i] * M.vec[i]);
		return total;
	}

	public double sum(){
		double total = 0.0;
		for(int i = 0; i<vecShape; i++)
			total += vec[i];
		return total;
	}

	public double mean(){
		double val = sum()/vecShape;
		return val;
	}

	public ArrayType square(){
		Vector m = new Vector(vecShape);
		for(int i = 0; i<vecShape; i++)
			m.vec[i] = vec[i] * vec[i];		
		return m;
	}

	public Vector add(Vector M){
		// size mismatch
		Vector m = new Vector(vecShape);
		for(int i = 0; i<vecShape; i++)
			m.vec[i] = (vec[i] + M.vec[i]);		
		return m;		
	}

	public Vector sub(Vector M){
		// size mismatch
		Vector m = new Vector(vecShape);
		for(int i = 0; i<vecShape; i++)
			m.vec[i] = (vec[i] - M.vec[i]);		
		return m;		
	}

	public Vector multiply(Vector M){
		// size mismatch
		Vector m = new Vector(vecShape);
		for(int i = 0; i<vecShape; i++)
			m.vec[i] = (vec[i] * M.vec[i]);		
		return m;		
	}

	public Vector scale(double factor){
		Vector m = new Vector(vecShape);
		for(int i = 0; i<vecShape; i++)
			m.vec[i] = (factor * vec[i]);		
		return m;		
	}

	public Vector scale(Vector factors){
		// size mismatch
		Vector m = new Vector(vecShape);
		for(int i = 0; i<vecShape; i++)
			m.vec[i] = (factors.vec[i] * vec[i]);		
		return m;		
	}

}