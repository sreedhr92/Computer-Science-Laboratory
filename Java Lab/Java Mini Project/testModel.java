import Arrays.*;
import LinearRegression.*;
import Data.LoadData;

public class testModel{
	public static void main(String args[]){
		Model model = new Model();
		LoadData D = new LoadData();

		D.loadData("C:\\Users\\siddh\\Admission_Predict.csv");
		D.normalizeData();

		double x[][] = new double[400][8];
		double ys[] = D.yValues;

		for(int i=0; i<400; i++)
		{
			x[i][0] = (double) 1;
			for(int j=1; j<8; j++)
				x[i][j] = D.xValues[i][j-1];
		}

		double m[] = new double[8];
		double s[] = new double[8];

		s[0] = s[7] = (double) 1;
		for(int i=1; i<7; i++){
			m[i] = D.mean[i-1];
			s[i] = 1/D.sd[i-1];
		}

		Vector mean = new Vector(m);
		Vector std_inv = new Vector(s);

		model.set_params(0.001, 100, 0, mean, std_inv);

		Matrix X = new Matrix(x);
		Vector y = new Vector(ys);
		model.fit(X, y);

		Vector [] ret = {mean, std_inv, model.theta};
	}
}
