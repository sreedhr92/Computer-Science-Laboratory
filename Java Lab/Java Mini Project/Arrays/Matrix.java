// Class for matrix operations

package Arrays;
import java.util.*;

public class Matrix implements ArrayType{
	public double mat[][];
	private int matShape[];

	public void init(String in){
		if(in.equals("ones")){
			for(int i = 0; i<matShape[0]; i++)
				for(int j = 0; j<matShape[1]; j++)
					mat[i][j] = (double)1;
		}
		else if(in.equals("random")){
			Random r = new Random();
			for(int i = 0; i<matShape[0]; i++)
				for(int j = 0; j<matShape[1]; j++)
					mat[i][j] = r.nextGaussian();
		}
		else{
			// throw exception
			// invalid string
		}
	}

	public Matrix(int m, int n, String...in){
		matShape = new int[2];
		matShape[0] = m;
		matShape[1] = n;

		mat = new double[m][n];

		if(in.length > 1);
			// throw exception
		if(in.length == 0)
			return;
		init(in[0]);
	}

	public Matrix(int n, String...in){
		
		matShape = new int[2];
		matShape[0] = matShape[1] = n;
		mat = new double[n][n];
		Random r = new Random();

		if(in.length > 1);
			// throw exception
		if(in.length == 0)
			return;
		init(in[0]);
	}

	public Matrix(double matrix[][]){
		matShape = new int[2];		
		matShape[0] = matrix.length;
		matShape[1] = matrix[0].length;
		mat = matrix;
	}

	public int[] shape(){
		return matShape;
	}

	public Matrix dot(Matrix M2){
		// Size mismatch exception
		Matrix P = new Matrix(matShape[0], M2.shape()[1]);
		for(int i=0; i<P.shape()[0]; i++) 
			for(int j=0; j<P.shape()[1]; j++)
				for(int k=0; k<matShape[1]; k++)     
					P.mat[i][j] = (P.mat[i][j] + mat[i][k] * M2.mat[k][j]);
		return P;
	}

	public Matrix transpose(){
		Matrix P = new Matrix(matShape[1], matShape[0]);
		for(int i=0; i<P.shape()[0]; i++) 
			for(int j=0; j<P.shape()[1]; j++)
				P.mat[i][j] = mat[j][i];
		return P;
	}

	public Vector dot(Vector V){
		// Size mismatch exception.
		Vector P = new Vector(matShape[0]);
		for(int i=0; i<matShape[0]; i++) 
			for(int k=0; k<matShape[1]; k++)     
				P.vec[i] += mat[i][k] * V.vec[k];
		return P;
	}

	public double sum(){
		double total = 0.0;
		for(int i = 0; i<matShape[0]; i++)
			for(int j = 0; j<matShape[1]; j++)
				total = (total + mat[i][j]);
		return total;
	}

	public double[] sum(int axis){
		double total[] = new double[matShape[axis]];
		if(axis == 0){
			for(int i = 0; i<matShape[0]; i++)
				for(int j = 0; j<matShape[1]; j++)
					total[j] = (total[j] + mat[i][j]);
		}
		else if(axis == 1){
			for(int i = 0; i<matShape[1]; i++)
				for(int j = 0; j<matShape[0]; j++)
					total[j] = (total[j] + mat[i][j]);
		}
		else{
			// Invalid axis
		}
		return total;
	}

	public double mean(){
		double val = (sum()/(matShape[0] * matShape[1]));
		return val;
	}

	public double[] mean(int axis){
		if(axis<0 || axis>1);
			// Invalid axis
		double vals[] = sum(axis);
		double meanArray[] = new double[matShape[~axis]];
		for(int i = 0; i<(~axis); i++)
			meanArray[i] = (vals[i] / matShape[axis]);
		return meanArray;
	}

	public ArrayType square(){
		Matrix m = new Matrix(matShape[0], matShape[1]);
		for(int i = 0; i<matShape[0]; i++)
			for(int j = 0; j<matShape[1]; j++)
				m.mat[i][j] = (mat[i][j] * mat[i][j]);		
		return m;
	}

	public Matrix add(Matrix M){
		// size mismatch
		Matrix m = new Matrix(matShape[0], matShape[1]);
		for(int i = 0; i<matShape[0]; i++)
			for(int j = 0; j<matShape[1]; j++)
				m.mat[i][j] = (mat[i][j] + M.mat[i][j]);		
		return m;		
	}

	public Matrix sub(Matrix M){
		// size mismatch
		Matrix m = new Matrix(matShape[0], matShape[1]);
		for(int i = 0; i<matShape[0]; i++)
			for(int j = 0; j<matShape[1]; j++)
				m.mat[i][j] = (mat[i][j] - M.mat[i][j]);		
		return m;		
	}

	public Matrix multiply(Matrix M){
		// size mismatch
		Matrix m = new Matrix(matShape[0], matShape[1]);
		for(int i = 0; i<matShape[0]; i++)
			for(int j = 0; j<matShape[1]; j++)
				m.mat[i][j] = (mat[i][j] * M.mat[i][j]);		
		return m;		
	}

	public Matrix scale(double factor){
		Matrix m = new Matrix(matShape[0], matShape[1]);
		for(int i = 0; i<matShape[0]; i++)
			for(int j = 0; j<matShape[1]; j++)
				m.mat[i][j] = (factor * mat[i][j]);		
		return m;		
	}
}