import {CGFobject} from '../lib/CGF.js';
/**
 * MyDiamond
 * @constructor
 * @param scene - Reference to MyScene object
 */
export class MyUnitCube extends CGFobject {
	constructor(scene) {
		super(scene);
		this.initBuffers();
	}
	
	initBuffers() {
		this.vertices = [
			0.5, 0.5, -0.5,	        //0
			0.5, -0.5,-0.5,	        //1
			-0.5, -0.5, -0.5,   	//2
			-0.5, 0.5, -0.5,		//3
        
            0.5, 0.5, 0.5,	        //4
			0.5, -0.5, 0.5,	        //5
			-0.5, -0.5, 0.5,   	    //6
			-0.5, 0.5, 0.5,         //7
        ];

		//Counter-clockwise reference of vertices
		this.indices = [
            // faces xy
            //1
            7, 6, 4,
            4, 6, 5,
            //2
            0, 2, 3,
            1, 2, 0,
            // faces yz
            //1
            4, 5, 0,
            0, 5, 1,
            //2
            3, 6, 7,
            2, 6, 3,
            // faces zx
            //1
            0, 7, 4, 
            3, 7, 0,
            //2
            5, 6, 1, 
            1, 6, 2
		];

		//The defined indices (and corresponding vertices)
		//will be read in groups of three to draw triangles
		this.primitiveType = this.scene.gl.TRIANGLES;

		this.initGLBuffers();
	}
}

