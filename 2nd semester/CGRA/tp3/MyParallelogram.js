import {CGFobject} from '../lib/CGF.js';
/**
 * MyTriangle
 * @constructor
 * @param scene - Reference to MyScene object
 */
export class MyParallelogram extends CGFobject {
	constructor(scene) {
		super(scene);
		this.initBuffers();
	}
	
	initBuffers() {
		this.vertices = [
			0, 0, 0,	//0
			1, 0, 0,	//1
            1, 1, 0,	//2
            2, 0, 0,    //3
            3, 1, 0,    //4
            2, 1, 0     //5
		];

		//Counter-clockwise reference of vertices
		this.indices = [
            2, 1, 0,
            1, 5, 2,
            1, 3, 5,
            3, 4, 5, 
            //para ser vizivel em ambos lados
            0, 1, 2,   
            2, 5, 1,
            5, 3, 1,
            5, 4, 3 
		];

		//The defined indices (and corresponding vertices)
		//will be read in groups of three to draw triangles
		this.primitiveType = this.scene.gl.TRIANGLES;

		this.initGLBuffers();
	}
}

