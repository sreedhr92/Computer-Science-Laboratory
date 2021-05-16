import Arrays.*;

public class testMatrix{
	public static void main(String args[]){
		Matrix a = new Matrix(3, 4);
		Matrix b = new Matrix(3, 4);
		Vector v = new Vector(4, "ones");
		//for(int i=0; i<4; i++)
		//	v.vec[i] = i+(double)3;
		for(int i=0; i<4; i++)
			System.out.println(v.vec[i]);
		
		for(int i=0; i<3; i++)
			for(int j=0; j<4; j++){
				a.mat[i][j] = (double)(1);
				b.mat[i][j] = (double)(i - j);	
			}
		Vector c = a.dot(v);
		for(int i=0; i<c.shape(); i++){
			System.out.print(c.vec[i] + " ");
		}		
	}
}