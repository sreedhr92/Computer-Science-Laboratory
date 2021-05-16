import React from 'react'; 
import {Switch, Route,Link,Redirect} from 'react-router-dom';
import Committe from './component/Committe';
import Contact from './component/Contact';
import Dates from './component/Dates';
import Home from './component/Home';
import Papers from './component/Papers';
import Registration from './component/Registration';
import Workshop from './component/Workshop';


function App() {
  return (
    <div>
      <p /><h2 style={{color: 'gray'}}>Welcome to the 70th International Conference on Gaming.</h2><p />
        <hr className="solid" />
        <i style={{color: 'f08a5d'}}><strong>Here are the links for your references:</strong></i>
        <br />
      <div className="topnav">
	  	<Link to="/home" data-toggle="tooltip" title="This directs you to home page">Home </Link>
	  	<Link to="/committe" data-toggle="tooltip" title="This directs you to Committee organisation page">Committee </Link>
	  	<Link to="/papers" data-toggle="tooltip" title="This directs you to Call for Paper page">Call For Papers </Link>
	  	<Link to="/dates" data-toggle="tooltip" title="This directs you to Important dates page">Important Dates </Link>
	  	<Link to="/workshop" data-toggle="tooltip" title="This directs you to Workshops page">Workshops </Link>
	  	<Link to="/registration" data-toggle="tooltip" title="This directs you to New Registration page">Registration </Link>
	  	<Link to="/contact" data-toggle="tooltip" title="This directs you to Contact page">Contact</Link>
	  </div>
      <Switch>
      <Route path="/Home"><br />
        <Home/>
      </Route>
      <Route path="/Papers"><br />
        <Papers />
      </Route>
      <Route path="/Dates"><br />
        <Dates />
      </Route>
      <Route path="/Workshop"><br />
        <Workshop />
      </Route>
      <Route path="/Registration"><br />
        <Registration />
      </Route>
      <Route path="/Contact"><br />
        <Contact /> 
      </Route>
      <Route path="/Committe"><br />
        <Committe />
      </Route>
    </Switch>
    <Redirect to="/Home"></Redirect>
    </div>
    
  );
}

export default App;
