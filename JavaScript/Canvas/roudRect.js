//扩展一个画圆角矩形的方法
//参数：第一点的横坐标，第一点的纵坐标，直线的宽度，直线的高度，圆角的半径
CanvasRenderingContext2D.prototype.roundRect = function (x, y, w, h, r) {	
    this.beginPath();
    if(w>0)	{
    	this.moveTo(x+r,y);
        this.lineTo(x+r+w,y);
        this.arc(x+r+w,y+r,r,3*Math.PI/2,2*Math.PI,false);
        this.lineTo(x+2*r+w,y+r+h);
        this.arc(x+r+w,y+r+h,r,0,Math.PI/2,false);
        this.lineTo(x+r,y+2*r+h);
        this.arc(x+r,y+r+h,r,Math.PI/2,Math.PI,false);
        this.lineTo(x,y+r);
        this.arc(x+r,y+r,r,Math.PI,3*Math.PI/2,false);

    }
    else {
    	this.moveTo(x,y+r);
        this.lineTo(x,y+r+h);
        this.arc(x-r,y+r+h,r,0,Math.PI/2,false);
        this.lineTo(x-r+w,y+2*r+h);
        this.arc(x-r+w,y+r+h,r,Math.PI/2,Math.PI,false);
        this.lineTo(x-2*r+w,y+r+h);
        this.arc(x-r+w,y+r,r,Math.PI,3*Math.PI/2,false);
        this.lineTo(x-r,y);
        this.arc(x-r,y+r,r,3*Math.PI/2,2*Math.PI,false);
    }
    this.closePath();
    return this;
}

