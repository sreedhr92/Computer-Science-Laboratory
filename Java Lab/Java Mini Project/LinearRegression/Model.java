// Class for the ML model.

package LinearRegression;

import Arrays.*;
import java.util.ArrayList;
import java.util.Iterator;

public class Model{

	private double learning_rate;
	private int steps;
	private double lambda;
	private Vector mean;
	private Vector std_inverse;
	public Vector theta;
	private ArrayList<Double> losses;

	public Model(){
		losses = new ArrayList<Double>();
		lambda = 0.0;
		learning_rate = 0.01;
		steps = 300;
	}

	public void set_params(double learning_rate, int steps, double l2_factor, Vector mean, Vector std){
		this.learning_rate = learning_rate;
		this.steps = steps;
		this.lambda = l2_factor;
		this.mean = mean;
		this.std_inverse = std;
	}

	private Vector initTheta(int shape){
		return new Vector(shape);
	}	

	private Vector model(Matrix X, Vector theta){
		return X.dot(theta);
	}

	private double mseLoss(Vector y_true, Vector y_pred){
		return y_pred.sub(y_true).square().mean() + lambda * (theta.square().sum() - (theta.vec[0] * theta.vec[0]));
	}

	private Vector calcGrad(Matrix X, Vector theta, Vector y){
		return X.transpose().dot(model(X, theta).sub(y));
	}

	private void graphLoss(){

	}

	public void fit(Matrix X, Vector y){
		theta = initTheta(X.shape()[1]);
		Vector pred, gradients;
	
		for(int i=0; i<steps; i++){
			pred = model(X, theta);
			losses.add(mseLoss(y, pred));
			gradients = calcGrad(X, theta, y);
			theta = theta.sub(gradients.scale(learning_rate));
		}

		System.out.print("\nLast Loss: " + losses.get(losses.size()-1));
			
		graphLoss();
	}
	
	public double predict(Vector x){
		return x.sub(mean).scale(std_inverse).dot(theta);
	}

}