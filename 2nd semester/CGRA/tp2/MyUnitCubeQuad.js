import { CGFobject } from '../lib/CGF.js';
import { MyQuad } from "./MyQuad.js";

/**
 * MyTriangle
 * @constructor
 * @param scene - Reference to MyScene object
 */
export class MyUnitCubeQuad extends CGFobject {
    constructor(scene) {
    	super(scene);
    	this.sc = scene;
        this.quad = new MyQuad(scene);
    }
    display() {
        this.quad.display();
        
        this.sc.pushMatrix();
        this.sc.translate(0, -0.5, -0.5);
        this.sc.rotate(Math.PI/2, 1, 0, 0);
        this.quad.display();
        this.sc.popMatrix();

        this.sc.pushMatrix();
        this.sc.translate(0, 0.5, -0.5);
        this.sc.rotate(-Math.PI/2, 1, 0, 0);
        this.quad.display();
        this.sc.popMatrix();

        this.sc.pushMatrix();
        this.sc.translate(0.5, 0, -0.5);
        this.sc.rotate(Math.PI/2, 0, 1, 0);
        this.quad.display();
        this.sc.popMatrix();

        this.sc.pushMatrix();
        this.sc.translate(-0.5, 0, -0.5);
        this.sc.rotate(-Math.PI/2, 0, 1, 0);
        this.quad.display();
        this.sc.popMatrix();

        this.sc.pushMatrix();
        this.sc.translate(0, 0, -1);
        this.sc.rotate(Math.PI, 1, 0, 0);
        this.quad.display();
        this.sc.popMatrix();
    }
}

