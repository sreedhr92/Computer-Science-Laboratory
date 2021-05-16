var array = [1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8];
var select = [-1,-1];
var id = [-1,-1];
var score =0;
var time =100;
var moves = 0;
var match = 0;
var level = 1;
function eve(){
    document.getElementById("1").addEventListener("click",function()
    {
        document.getElementById("1").style.transform="rotateY(-180deg)";
        cal(1);
    });
    document.getElementById("2").addEventListener("click",function()
    {
        document.getElementById("2").style.transform="rotateY(-180deg)";
        cal(2);
    });
    document.getElementById("3").addEventListener("click",function()
    {
        document.getElementById("3").style.transform="rotateY(-180deg)";
        cal(3);
    });
    document.getElementById("4").addEventListener("click",function()
    {
        document.getElementById("4").style.transform="rotateY(-180deg)";
        cal(4);
    });
    document.getElementById("5").addEventListener("click",function()
    {
        document.getElementById("5").style.transform="rotateY(-180deg)";
        cal(5);
    });
    document.getElementById("6").addEventListener("click",function()
    {
        document.getElementById("6").style.transform="rotateY(-180deg)";
        cal(6);
    });
    document.getElementById("7").addEventListener("click",function()
    {
        document.getElementById("7").style.transform="rotateY(-180deg)";
        cal(7);
    });
    document.getElementById("8").addEventListener("click",function()
    {
        document.getElementById("8").style.transform="rotateY(-180deg)";
        cal(8);
    });
    document.getElementById("9").addEventListener("click",function()
    {
        document.getElementById("9").style.transform="rotateY(-180deg)";
        cal(9);
    });
    document.getElementById("10").addEventListener("click",function()
    {
        document.getElementById("10").style.transform="rotateY(-180deg)";
        cal(10);
    });
    document.getElementById("11").addEventListener("click",function()
    {
        document.getElementById("11").style.transform="rotateY(-180deg)";
        cal(11);
    });
    document.getElementById("12").addEventListener("click",function()
    {
        document.getElementById("12").style.transform="rotateY(-180deg)";
        cal(12);
    });
    document.getElementById("13").addEventListener("click",function()
    {
        document.getElementById("13").style.transform="rotateY(-180deg)";
        cal(13);
    });
    document.getElementById("14").addEventListener("click",function()
    {
        document.getElementById("14").style.transform="rotateY(-180deg)";
        cal(14);
    });
    document.getElementById("15").addEventListener("click",function()
    {
        document.getElementById("15").style.transform="rotateY(-180deg)";
        cal(15);
    });
    document.getElementById("16").addEventListener("click",function()
    {
        document.getElementById("16").style.transform="rotateY(-180deg)";
        cal(16);
    });
}
eve();
var myVar;
myVar = setInterval(timer, 1000);
function init(){
    for (var i=0;i< array.length; i++) {
        var j = Math.floor(Math.random() * (i + 1));
        var temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    document.getElementById("over").style.visibility="hidden";
    for(var i=1;i<17;i++)
    {
        document.getElementById(i).style.visibility="visible";
        document.getElementById(i).lastElementChild.firstElementChild.src=array[i-1]+'.png';
    }
}
function timer(){
    document.getElementById("test").innerHTML="Time :"+time;
    document.getElementById("score").innerHTML="Score :"+score;
    document.getElementById("steps").innerHTML="Steps :"+moves;
    time--;
    if(time<=0)
    {
        document.getElementById("over").style.visibility="visible";
        document.getElementById("test").style.visibility="hidden";
        document.getElementById("over").innerHTML="Game Over\n Refresh to play again";
        for(var i=1;i<17;i++)
        {
            document.getElementById(i).style.visibility="hidden";
        }
        setTimeout(function(){clearInterval(myVar);},5000);
    }
}
function cal(i)
{
    moves++;
    if(select[0]!=-1 && select[1]!=-1)
    {
        document.getElementById(i).style.transform='rotateY(0deg)';
        return;
    }
        
    if(select[0]==-1)
    {
        select[0]=array[i-1];
        id[0] = i;
    }
    else if(select[1]==-1 && i!=id[0])
    {
        select[1]=array[i-1];
        id[1]=i;
        setTimeout(eval,1000);
    }
}
function reset(){
        window.alert("Level :"+level+"\nGame Over\nYour Score is "+score);
        match=0;
        moves=0;
        level++;
        for(var i=1;i<17;i++)
        {
            document.getElementById(i).style.transform='rotateY(0deg)';
        }
        if(level==2)
        {
            time=70;
        }
        if(level==3)
        {
            time=50;
        }
        if(level==4)
        {
            document.getElementById("over").style.visibility="visible";
            document.getElementById("test").style.visibility="hidden";
            document.getElementById("over").innerHTML="Game Over\n Refresh to play again";
            for(var i=1;i<17;i++)
            {
               document.getElementById(i).style.visibility="hidden";
            }
            setTimeout(function(){clearInterval(myVar);},5000);
        }
        clearInterval(myVar);
        myVar = setInterval(timer, 1000);
        select =[-1,-1];
        id=[-1,-1];
        init();
}
function eval()
{
    if(select[0]==select[1])
    {
        score+=50;
        match++;
        document.getElementById(id[0]).style.visibility="hidden";
        document.getElementById(id[1]).style.visibility="hidden";
        select =[-1,-1];
        id=[-1,-1];
    }
    else
    {
        score-=10;
        document.getElementById(id[0]).style.transform='rotateY(0deg)';
        document.getElementById(id[1]).style.transform='rotateY(0deg)';
        select =[-1,-1];
        id=[-1,-1];
    }
    if(match==8)
    {
        reset();
    }
}
init();