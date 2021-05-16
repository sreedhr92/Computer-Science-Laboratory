import React from 'react';
import logo_2 from './lg1.jpg';

const Papers = () => {
    return ( <div>
        <img src={logo_2} width={100} height={80} alt="Page logo" />
        <h2>International Gaming Conference Papers</h2>
        <hr className="solid" />
        <br /><br />
        `	<div className="outline">
          <p><strong>General-Chair   :</strong><i>  PewDiePie</i><br /><strong>Program-chair   :</strong><i>MrBeast</i><br />
            <strong>Publisher     :</strong><i>Association for Computing Machinery,New York,NY,United States.</i><br />
            <strong>Conference    :</strong><i>    Conference on Intense gaming</i><br />
            <strong>Sponser       :</strong><i>    ROG,ASUS,ACER,RAZER</i><br />
          </p>
          <p><strong>General-Chair   :</strong><i>  Lazer Beam</i><br /><strong>Program-chair   :</strong><i>Dream</i><br />
            <strong>Publisher     :</strong><i>Association for Computing Machinery,New York,NY,United States.</i><br />
            <strong>Conference    :</strong><i>    Conference on Midnight gaming</i><br />
            <strong>Sponser       :</strong><i>    APPLE,BLACK SHARK,RED MAGIC,RAZER</i><br />
          </p>
        </div>
        <a href="index.html" target="_blank" data-toggle="tooltip" title="This directs you to index page"><i className="fas fa-arrow-left" /></a>
        <footer>
          <p style={{color: 'gray'}}>Author: Sreedhar V
            <br /> <a href="mailto:sreedhar18161@cse.ssn.edu.in">Mail id</a></p>
          <i>©Gaming techs designs</i><br />
          <a href="index.html" target="_blank" data-toggle="tooltip" title="This directs you to index page"><i className="fas fa-arrow-left" /></a>
        </footer>
    </div>);
}
 
export default Papers;