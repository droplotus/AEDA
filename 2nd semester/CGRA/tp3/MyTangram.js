import { CGFobject } from '../lib/CGF.js';

import { MyDiamond } from "./MyDiamond.js";
import { MyTriangle } from "./MyTriangle.js";
import { MyParallelogram } from "./MyParallelogram.js";
import { MyTriangleSmall } from "./MyTriangleSmall.js";
import { MyTriangleBig } from "./MyTriangleBig.js";
/**
 * MyTriangle
 * @constructor
 * @param scene - Reference to MyScene object
 */
export class MyTangram extends CGFobject {
    constructor(scene) {
    	super(scene);
    	this.sc = scene;
	    this.diamond = new MyDiamond(scene);
	    this.triangle = new MyTriangle(scene);
	    this.parallelogram = new MyParallelogram(scene);
	    this.trianglesmall = new MyTriangleSmall(scene);
	    this.trianglebig = new MyTriangleBig(scene);
    }
    display() {

        //display diamond
        var a = -20;
        var rot = [
	        Math.cos(a*Math.PI/180), Math.sin(a*Math.PI/180), 0, 0, 
	        -Math.sin(a*Math.PI/180), Math.cos(a*Math.PI/180), 0, 0,
	        0, 0, 1, 0, 
	        0, 0, 0, 1
        ];

        var trans = [
	        1, 0, 0, 0,
	        0, 1, 0, 0, 
	        0, 0, 1, 0, 
	        -0.9, 0.3, 0, 1
        ];

        this.sc.pushMatrix();
        this.sc.multMatrix(trans);
        this.sc.multMatrix(rot);
        this.diamond.display();
        this.sc.popMatrix();
    
    	//display triangle
		this.sc.pushMatrix();
		this.sc.translate(0.6, 1.62, 0);
		this.sc.rotate(3*Math.PI/4, 0, 0, 1);
		this.triangle.display();
		this.sc.popMatrix();
    
    	//display parallelogram
		this.sc.pushMatrix();
		this.sc.rotate(Math.PI, 0, 1, 0);
		this.sc.translate(1.7, -3.57, 0);
		this.sc.rotate(3*Math.PI/4, 0, 0, 1);
		this.parallelogram.display();
		this.sc.popMatrix();
    
    	//display small triangle
		this.sc.pushMatrix();
		this.sc.translate(0.6, 3.9, 0);
		this.sc.rotate(Math.PI/2, 0, 0, 1);
		this.trianglesmall.display();
		this.sc.popMatrix();

		this.sc.pushMatrix();
		this.sc.translate(-0.27, 3.3, 0);
		this.sc.rotate(150*Math.PI/180, 0, 0, 1);
		this.trianglesmall.display();
		this.sc.popMatrix();
    
    	//display big triangle
		this.sc.pushMatrix();
		this.sc.translate(-0.2, -2.16, 0);
		this.trianglebig.display();
		this.sc.popMatrix();

		this.sc.pushMatrix();
		this.sc.translate(2, -0.35, 0);
		this.sc.rotate(90*Math.PI/180, 0, 0, 1);
		this.trianglebig.display();
		this.sc.popMatrix();
   
    }
}

