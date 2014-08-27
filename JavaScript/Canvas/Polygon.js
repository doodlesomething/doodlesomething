//Polygon类用于绘制多边形	
//创建多边形对象和方法
var Point=function(x,y)	{
	this.x=x;
	this.y=y;
}
//传参说明：centerX、centerY多边形的中心坐标，radius多边形对应圆的半径,边框色，填充色，是否有填充色
var Polygon=function(centerX,centerY,radius,sides,startAngle,strokeStyle,fillStyle,filled)	{
	this.x=centerX;
	this.y=centerY;
	this.radius=radius;
	this.sides=sides;
	this.startAngle=startAngle;
	this.strokeStyle=strokeStyle;
	this.fillStyle=fillStyle;
	this.filled=filled;
}

Polygon.prototype={
	//获取各个点
	getPoints:function()	{
		var points=[];
		var angle=this.startAngle||0;
		for(var i=0;i<this.sides;i++)	{
		points.push( new Point(this.x+this.radius*Math.sin(angle),this.y-this.radius*Math.cos(angle) ) );
		angle+=Math.PI*2/this.sides;
		}
		
		return points;
	},
	//创建路径
	createPath:function(context)	{
		var points=this.getPoints();
		context.beginPath();
		context.moveTo(points[0].x,points[0].y);
		for(var i=1;i<this.sides;i++)
			context.lineTo(points[i].x,points[i].y);
		context.closePath();
	},
	//描边
	stroke:function(context)	{
		context.save();
		this.createPath(context);
		context.strokeStyle=this.strokeStyle;
		context.stroke();
		context.restore();
	},
	//填充
	fill:function(context)	{
		context.save();
		this.createPath(context);
		context.fillStyle=this.fillStyle;
		if(this.filled)
			context.fill();
		context.restore();
	},
	
	//这个方法可以在真正绘制前移动多边形
	move:function(x,y)	{
		this.x=x;
		this.y=y;
	}

};

