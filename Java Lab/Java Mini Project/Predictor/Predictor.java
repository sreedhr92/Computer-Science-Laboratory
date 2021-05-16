package Predictor;
import Arrays.*;

public class Predictor{

	static double arr[] = {0.7091553898004078, 0.01831283536326234, 0.018462943881280034, 0.006497367935507093, -0.003661704937853909, 0.02006119582658256,

0.07106699467828549, 0.02740290704811719};
	static double s[] = {1.0,0.0872654027097274,0.16496417758799328,0.8754286289567393,0.9944220203272562,1.1143877223878258,1.679060276028006,1.0};
	static double m[] = {0.0,316.8075,107.41,3.0875,3.4,3.4525,8.598924999999998,0.0};
	
	static Vector p = new Vector(arr);
	static Vector me = new Vector(m);
	static Vector sd = new Vector(s);
	static Vector in = new Vector(x);

	public static double pred(double x[]){
		return in.sub(me).scale(sd).dot(p);
	}
}