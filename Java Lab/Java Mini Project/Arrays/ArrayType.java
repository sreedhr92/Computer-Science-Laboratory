// Interface for array-like structures

package Arrays;

public interface ArrayType{
	double mean();
	double sum();
	ArrayType square();
	void init(String init);
}